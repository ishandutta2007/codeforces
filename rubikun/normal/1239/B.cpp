#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    vector<int> cnt(N+1,0);
    int mini=INF,left=INF,right=-1;
    for(int i=0;i<N;i++){
        if(S[i]=='(') cnt[i+1]=cnt[i]+1;
        else cnt[i+1]=cnt[i]-1;
        mini=min(mini,cnt[i+1]);
    }
    
    if(cnt[N]!=0){
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    
    int ans=0,ansleft=INF,ansright=-1,res=0;
    
    res=0;
    left=INF;right=-1;
    for(int i=1;i<=N;i++) if(cnt[i]==mini) res++;
    if(res>ans){
        ans=res;
        ansleft=1;
        ansright=0;
    }
    
    res=0;
    left=INF;right=-1;
    
    for(int i=0;i<N;i++){
        if(cnt[i+1]==mini||cnt[i+1]==mini+1){
            left=min(left,i+1);
            right=max(right,i+1);
        }
    }
    
    for(int i=1;i<=N;i++){
        if(left<=i&&i<=right){
            if(cnt[i]==mini) res++;
        }else{
            if(cnt[i]==mini+2) res++;
        }
    }
    
    if(res>ans&&right!=N){
        ans=res;
        ansleft=left;
        ansright=right;
    }
    
    res=0;
    left=INF;right=-1;
    
    for(int i=0;i<N;i++){
        if(cnt[i+1]==mini){
            left=min(left,i+1);
            right=max(right,i+1);
        }
    }
    
    for(int i=1;i<=N;i++){
        if(left<=i&&i<=right){
            if(cnt[i]==mini-1) res++;
        }else{
            if(cnt[i]==mini+1) res++;
        }
    }
    
    if(res>ans&&right!=N){
        ans=res;
        ansleft=left;
        ansright=right;
    }//
    
    vector<int> sum1(N+1,0),sum2(N+1,0);//=mini,=mini-1
    
    for(int i=1;i<=N;i++){
        if(cnt[i]==mini) sum1[i]=sum1[i-1]+1;
        else sum1[i]=sum1[i-1];
        
        if(cnt[i]==mini-1) sum2[i]=sum2[i-1]+1;
        else sum2[i]=sum2[i-1];
    }
    
    int s=0;
    while(s<N){
        res=0;
        left=INF;right=-1;
        
        for(int i=s;i<N;i++){
            if(cnt[i+1]==mini+2){
                left=min(left,i+1);
                right=max(right,i+1);
            }
            if(left!=INF&&(cnt[i+1]==mini||cnt[i+1]==mini+1)){
                s=i+1;
                break;
            }
            if(i==N-1) s=N;
        }
        
        res+=sum1[left-1];
        res+=sum1[N]-sum1[right];
        
        for(int i=left;i<=right;i++){
            if(cnt[i]==mini+2) res++;
        }
        
        /*for(int i=1;i<=N;i++){
            if(left<=i&&i<=right){
                if(cnt[i]==mini+2) res++;
            }else{
                if(cnt[i]==mini) res++;
            }
        }*/
        
        if(res>ans&&right!=N){
            ans=res;
            ansleft=left;
            ansright=right;
        }
    }
    
    s=0;
    while(s<N){
        res=0;
        left=INF;right=-1;
        
        for(int i=s;i<N;i++){
            if(cnt[i+1]==mini+1){
                left=min(left,i+1);
                right=max(right,i+1);
            }
            if(left!=INF&&(cnt[i+1]==mini)){
                s=i+1;
                break;
            }
            if(i==N-1) s=N;
        }
        
        res+=sum2[left-1];
        res+=sum2[N]-sum2[right];
        
        for(int i=left;i<=right;i++){
            if(cnt[i]==mini+1) res++;
        }
        
        /*for(int i=1;i<=N;i++){
            if(left<=i&&i<=right){
                if(cnt[i]==mini+1) res++;
            }else{
                if(cnt[i]==mini-1) res++;
            }
        }*/
        
        if(res>ans&&right!=N){
            ans=res;
            ansleft=left;
            ansright=right;
        }
    }
    
    cout<<ans<<endl;
    cout<<ansleft<<" "<<ansright+1<<endl;
}