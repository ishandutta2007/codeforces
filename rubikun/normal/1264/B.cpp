#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=100000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a>b+1) cout<<"NO"<<endl;
    else if(a==b+1){
        if(c==0&&d==0){
            cout<<"YES"<<endl;
            for(int i=0;i<b;i++){
                cout<<"0 1 ";
            }
            cout<<0<<endl;
        }else cout<<"NO"<<endl;
    }else if(a==b&&a!=0){
        if(c>d+1) cout<<"NO"<<endl;
        else if(c==d+1){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"0 1 ";
            }
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<2<<endl;
        }else if(c==d){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"0 1 ";
            }
            for(int i=0;i<c;i++){
                cout<<"2 3 ";
            }
            cout<<endl;
        }else cout<<"NO"<<endl;
    }else if(a==b&&a==0){
        if(c==d+1){
            cout<<"YES"<<endl;
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<2<<endl;
        }else if(c==d){
            cout<<"YES"<<endl;
            for(int i=0;i<c;i++){
                cout<<"2 3 ";
            }
            cout<<endl;
        }else if(c+1==d){
            cout<<"YES"<<endl;
            for(int i=0;i<c;i++){
                cout<<"3 2 ";
            }
            cout<<3<<endl;
        }else cout<<"NO"<<endl;
    }else{
        
        b-=a;
        if(b+d==c){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"0 1 ";
            }
            for(int i=0;i<b;i++){
                cout<<"2 1 ";
            }
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<endl;
            return 0;
        }else if(b+d+1==c){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"0 1 ";
            }
            for(int i=0;i<b;i++){
                cout<<"2 1 ";
            }
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<2<<endl;
            return 0;
        }
        
        b+=a;
        
        b-=(a+1);
        
        if(b+d==c){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"1 0 ";
            }
            cout<<"1 ";
            for(int i=0;i<b;i++){
                cout<<"2 1 ";
            }
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<endl;
            return 0;
        }else if(b+d+1==c){
            cout<<"YES"<<endl;
            for(int i=0;i<a;i++){
                cout<<"1 0 ";
            }
            cout<<"1 ";
            for(int i=0;i<b;i++){
                cout<<"2 1 ";
            }
            for(int i=0;i<d;i++){
                cout<<"2 3 ";
            }
            cout<<2<<endl;
            return 0;
        }
        
        cout<<"NO"<<endl;
    }
    
}