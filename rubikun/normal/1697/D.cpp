#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

char ask1(int x){
    cout<<"? 1 "<<x+1<<endl;
    char c;cin>>c;
    return c;
}

int ask2(int l,int r){
    cout<<"? 2 "<<l+1<<" "<<r+1<<endl;
    int res;cin>>res;
    return res;
}

int main(){
    
    /*
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    */
    int N;cin>>N;
    string ans;
    int la=0;
    for(int i=0;i<N;i++){
        int res=ask2(0,i);
        if(la<res){
            ans+=ask1(i);
            la=res;
        }else{
            set<char> SE;
            vector<int> pos={-1};
            for(int j=i-1;j>=0;j--){
                if(!SE.count(ans[j])){
                    SE.insert(ans[j]);
                    pos.push_back(j);
                }
            }
            int left=0,right=si(pos)-1;
            while(right-left>1){
                int mid=(left+right)/2;
                int x=ask2(pos[mid],i);
                if(x==mid) right=mid;
                else left=mid;
            }
            
            ans+=ans[pos[right]];
        }
    }
    
    cout<<"! "<<ans<<endl;
}