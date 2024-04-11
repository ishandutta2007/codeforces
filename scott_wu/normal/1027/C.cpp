#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];

void run()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }
    sort (arr, arr + N);

    int nlast = -1;
    pair <int, int> lbest;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i-3])
        {
            printf("%d %d %d %d\n", arr[i], arr[i], arr[i], arr[i]);
            return;
        }
        if (arr[i] == arr[i-1])
        {
            if (arr[i] == nlast) continue;
            if (nlast == -1)
            {
                nlast = arr[i]; continue;
            }
            if (lbest.first == 0 || arr[i] * lbest.second < nlast * lbest.first)
                lbest = make_pair (arr[i], nlast);
            nlast = arr[i];
        }
    }
    printf("%d %d %d %d\n", lbest.first, lbest.first, lbest.second, lbest.second);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        run();
}