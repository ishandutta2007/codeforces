#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;


const int MAX_N = 1500;
int N;
int arr[MAX_N+1][MAX_N+1];
pii idx[MAX_N*MAX_N+1];

int cntx[MAX_N+1], cnty[MAX_N+1];



int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];        
            idx[arr[i][j]] = {i, j};
        }
    }
    ll ans = 0;
    for(int i=1; i<=N*N; i++){
        int nx = idx[i].first, ny = idx[i].second;
        int sx=0, lx=0, sy=0, ly=0;
        sx = cntx[nx];
        lx = N-sx-1;
        sy = cnty[ny];
        ly = N-sy-1;
        ans+=(ll)(sx*ly) + (ll)(lx*sy);
        cntx[nx]++;
        cnty[ny]++;
    }  
    cout<<ans/2;


    return 0;
}