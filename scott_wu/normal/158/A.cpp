#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int score[55];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> score[i];
    sort (score, score + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (score[i] >= score[n-k] && score[i] > 0)
            ans++;
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}