#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

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
    
    string S,T;cin>>S>>T;
    int cnts0=0,cnts1=0,cntt0=0,cntt1=0,per0=0,per1=0;
    
    for(int i=0;i<S.size();i++){
        if(S[i]=='0') cnts0++;
        else cnts1++;
    }
    
    KMP k;
    k.init(T);
    int period=T.size()-k.A[T.size()];
    
    for(int i=0;i<period;i++){
        if(T[i]=='0') cntt0++;
        else cntt1++;
    }
    per0=cntt0;
    per1=cntt1;
    
    int can=INF;
    
    if(cntt0!=0) can=min(can,cnts0/cntt0);
    if(cntt1!=0) can=min(can,cnts1/cntt1);
    
    for(int i=0;i<can;i++) cout<<T.substr(0,period);
    cnts0-=can*cntt0;
    cnts1-=can*cntt1;
    
    cntt0=0;cntt1=0;
    
    for(int i=period;i<T.size();i++){
        if(T[i]=='0') cntt0++;
        else cntt1++;
    }
    
    while(cntt0>=0&&cntt1>=0){
        if(cnts0>=cntt0&&cnts1>=cntt1){
            cnts0-=cntt0;
            cnts1-=cntt1;
            
            cout<<T.substr(period,T.size()-period);
            break;
        }
        cntt0-=per0;
        cntt1-=per1;
        period+=(per0+per1);
    }
    
    for(int i=0;i<cnts0;i++) cout<<'0';
    for(int i=0;i<cnts1;i++) cout<<'1';
    cout<<endl;
    
}