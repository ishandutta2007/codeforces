#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, M;
int arr[MAXN];
bool used[MAXN];
int partner[MAXN];

int nlast;

void receive()
{
    int x; cin >> x;
    x--;
    nlast = x;
    used[x] = true;
}

void answer (int x)
{
    cout << (x + 1) << endl;
    used[x] = true;
}

void act()
{
    if (nlast != -1 && partner[nlast] != -1 && !used[partner[nlast]])
    {
        answer (partner[nlast]);
        return;
    }

    int bval = -1e9, bloc = -1;
    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            if (partner[i] != -1)
            {
                int p = partner[i];
                if (!used[p] && arr[i] >= arr[p])
                {
                    bloc = i;
                    break;
                }
            }
            if (arr[i] > bval)
            {
                bval = arr[i];
                bloc = i;
            }
        }
    }
    answer (bloc);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    N *= 2;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        used[i] = false;
        partner[i] = -1;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        partner[a] = b;
        partner[b] = a;
    }

    nlast = -1;

    int t;
    cin >> t;
    for (int i = 0; i < N; i++)
    {
        if (t % 2 == i % 2)
        {
            receive();
        }
        else
        {
            act();
        }
    }
}