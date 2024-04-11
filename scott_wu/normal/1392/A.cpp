#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {

    cin >> N;
    bool bad = true;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] != arr[0]) bad = false;
    }
    if (bad) cout << N << "\n";
    else cout << "1\n";
    }
}