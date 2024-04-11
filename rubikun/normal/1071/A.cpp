#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b;cin>>a>>b;
    ll sum=0,i=1;
    for(;;i++){
        if(sum+i>a+b){
            i--;
            break;
        }
        sum+=i;
    }
    
    vector<int> ans1,ans2;
    for(int j=i;j>=1;j--){
        if(a>=b){
            ans1.push_back(j);
            a-=j;
        }else{
            ans2.push_back(j);
            b-=j;
        }
    }
    sort(all(ans1));
    sort(all(ans2));
    
    cout<<ans1.size()<<endl;
    for(int a:ans1) cout<<a<<" ";
    cout<<endl;
    
    cout<<ans2.size()<<endl;
    for(int a:ans2) cout<<a<<" ";
    cout<<endl;
}