#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,INF=1<<30;

vector<int> Zalgo(string S){
    vector<int> A(S.size());
    int c=0;
    for(int i=1;i<S.size();i++){
        if(i+A[i-c]<c+A[c]){
            A[i]=A[i-c];
        }else{
            int j=max(0,c+A[c]-i);
            while(i+j<S.size()&&S[j]==S[i+j]) j++;
            A[i]=j;
            c=i;
        }
    }
    A[0]=S.size();
    
    return A;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=S.size();
        
        if(N==1){
            cout<<S<<"\n";
            continue;
        }
        
        int left=0,right=N-1;
        
        while(left<=right){
            if(S[left]==S[right]){
                left++;
                right--;
            }else{
                break;
            }
        }
        
        string T,T2;
        for(int i=left;i<=right;i++){
            T+=S[i];
        }
        
        if(T.size()==0){
            cout<<S<<"\n";
            continue;
        }
        
        T2=T;
        reverse(all(T2));
        
        T+='&';
        T+=T2;
        
        vector<int> A=Zalgo(T);
        
        int ma=0,ma2=0;
        
        for(int i=A.size()/2;i<A.size();i++){
            if(A[i]==int(A.size())-i) ma=max(ma,A[i]);
        }
        
        //cout<<A.size()<<" "<<T<<endl;
        T2+='&';
        T2+=T.substr(0,int(T2.size())-1);
        
        A=Zalgo(T2);
        
        for(int i=A.size()/2;i<A.size();i++){
            if(A[i]==int(A.size())-i) ma2=max(ma2,A[i]);
        }
        //cout<<A.size()<<" "<<T2<<endl;
        string ans;
        
        if(ma>=ma2){
            ans+=S.substr(0,left);
            ans+=T.substr(0,ma);
            string U=S.substr(0,left);
            reverse(all(U));
            ans+=U;
        }else{
            ans+=S.substr(0,left);
            ans+=T2.substr(0,ma2);
            string U=S.substr(0,left);
            reverse(all(U));
            ans+=U;
        }
        
        cout<<ans<<"\n";
    }
}