#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define s second
#define ll long long
#define f first
#define mp make_pair
#define pb push_back
int use[N];
int main()
{
    sync;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #else
    #endif
    int n;
    cin>>n;
    if (n>1)
    {
    cout<<n<<" "<<n+1<<" "<<n*(n+1)<<endl;
    } else cout<<-1<<endl;
}