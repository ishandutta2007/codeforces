#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

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
    
    vector<int> match(string &C,string &T){
        init(C);
        vector<int> B;
        int m=0,i=0;
        
        while(m+i<T.size()){
            if(S[i]==T[m+i]){
                i++;
                if(i==S.size()){
                    B.push_back(m);
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
    
    int N;cin>>N;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    string ans;
    ans+=S[0];
    
    for(int i=1;i<N;i++){
        string T=S[i]+'?';
        if(ans.size()<=S[i].size()) T+=ans;
        else T+=ans.substr(ans.size()-S[i].size());
        
        KMP k;
        k.init(T);
        
        ans+=S[i].substr(k.A[k.A.size()-1]);
    }
    cout<<ans<<endl;
}