#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int MAX_N = 100;




int main()
{
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        int R=0, W=0;
        for(int i=0; i<M; i++){
            int r, w;
            scanf("%d%d",&r, &w);
            R = max(r, R);
            W = max(W, w);
        }
        string str;
        str.clear();
        for(int i=0; i<R; i++){
            str.pb('R');
        }
        for(int i=0; i<W; i++){
            str.pb('W');
        }
        while((int)str.size()<N){
            str.pb('W');
        }
        if(R+W>N){
            cout<<"IMPOSSIBLE\n";
        }else{
            cout<<str<<"\n";
        }
    }
    return 0;
}