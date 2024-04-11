#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N),cnt(101,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
        cnt[A[i]]++;
    }
    int sum=0,sel=0;
    for(int i=0;i<101;i++){
        if(cnt[i]==1) sum++;
        else if(cnt[i]>=3) sel++;
    }
    
    if(sum%2==1&&sel==0) cout<<"NO"<<endl;
    else if(sum%2==0){
        sum/=2;
        for(int i=0;i<101;i++){
            if(cnt[i]==1){
                if(sum>0) cnt[i]=0;
                else cnt[i]=1;
                
                sum--;
            }else cnt[i]=0;
        }
        
        cout<<"YES"<<endl;
        
        for(int i=0;i<N;i++){
            if(cnt[A[i]]==0) cout<<'A';
            else cout<<'B';
        }
        cout<<endl;
    }else{
        sum/=2;
        bool ok=false;
        for(int i=0;i<101;i++){
            if(cnt[i]==1){
                if(sum>0) cnt[i]=0;
                else cnt[i]=1;
                
                sum--;
            }else if(cnt[i]>=3){
                if(!ok){
                    ok=true;
                    cnt[i]=-1;
                }
                else cnt[i]=0;
            }else if(cnt[i]!=-1) cnt[i]=0;
        }
        
        cout<<"YES"<<endl;
        
        for(int i=0;i<N;i++){
            if(cnt[A[i]]==0) cout<<'A';
            else if(cnt[A[i]]==-1){
                cout<<'A';
                cnt[A[i]]=1;
            }else cout<<'B';
        }
        cout<<endl;
    }
}