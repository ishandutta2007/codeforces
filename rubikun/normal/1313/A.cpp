#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c;cin>>a>>b>>c;
        int res=0;
        if(a){
            res++;
            a--;
        }
        if(b){
            res++;
            b--;
        }
        if(c){
            res++;
            c--;
        }
        if(a>=b&&a>=c){
            if(a&&b){
                res++;
                a--;
                b--;
            }
            if(a&&c){
                res++;
                a--;
                c--;
            }
            if(b&&c){
                res++;
                b--;
                c--;
            }
        }else if(b>=a&&b>=c){
            if(a&&b){
                res++;
                a--;
                b--;
            }
            if(b&&c){
                res++;
                b--;
                c--;
            }
            if(a&&c){
                res++;
                a--;
                c--;
            }
        }else{
            if(b&&c){
                res++;
                b--;
                c--;
            }
            if(a&&c){
                res++;
                a--;
                c--;
            }
            if(a&&b){
                res++;
                a--;
                b--;
            }
        }
        if(a&&b&&c){
            res++;
        }
        cout<<res<<endl;
    }
}