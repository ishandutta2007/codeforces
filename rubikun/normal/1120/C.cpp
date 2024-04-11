#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005,INF=1<<30;

int dp[MAX];

struct KMP{
    vector<int> A;
    string S;
    
    void init(string &T){
        S=T;
        A.assign(S.size()+1,0);
        A[0]=-1;
        int j=-1;
        
        for(int i=0;i<S.size();i++){
            while(j>=0&&S[i]!=S[j]) j=A[j];
            j++;
            
            A[i+1]=j;
        }
    }
    
    int match(string &C,string &T){
        init(C);
        int B=-1;
        int m=0,i=0;
        
        while(m+i<T.size()){
            if(S[i]==T[m+i]){
                i++;
                if(i==S.size()){
                    B=m;
                    m+=i-A[i];
                    i=A[i];
                }
            }else{
                m+=i-A[i];
                if(i>0) i=A[i];
            }
        }
        
        return B;
    }//C(=S)T
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,A,B;cin>>N>>A>>B;
    string S;cin>>S;
    
    for(int i=0;i<=S.size();i++) dp[i]=INF;
    dp[0]=0;
    
    vector<KMP> K(S.size()+1);
    
    for(int i=0;i<=S.size();i++){
        string ss=S.substr(0,i);
        K[i].init(ss);
    }
    
    for(int i=0;i<S.size();i++){
        int left=i,right=int(S.size())+1;
        string sss=S.substr(0,i);
        while(right-left>1){
            int mid=(left+right)/2;
            string ss=S.substr(i,mid-i);
            int a=K[i].match(ss,sss);
            
            if(a!=-1) left=mid;
            else right=mid;
        }
        for(int to=i+1;to<=left;to++){
            dp[to]=min(dp[to],dp[i]+B);
        }
        dp[i+1]=min(dp[i+1],dp[i]+A);
    }
    
    cout<<dp[S.size()]<<endl;
}