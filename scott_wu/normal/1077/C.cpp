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
const int MAXN = 200100;

int N;
int arr[MAXN];

map <ll, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    ll ctot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ctot += arr[i];
        mm[arr[i]]++;
    }

    vector <int> ans;
    for (int i = 0; i < N; i++)
    {
        ctot -= arr[i];
        mm[arr[i]]--;
        if (ctot % 2 == 0 && mm[ctot/2])
            ans.push_back(i+1);
        ctot += arr[i];
        mm[arr[i]]++;
    }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}