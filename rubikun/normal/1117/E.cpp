#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string rem,s1,s2,s3,t1,t2,t3,qu;cin>>rem;
    int N=rem.size();
    vector<int> ans(N);
    
    for(int i=0;i<N;i++){
        s1+=char('a'+i/(26*26));
    }
    cout<<"? "<<s1<<endl;
    cin>>t1;
    
    for(int i=0;i<N;i++){
        s2+=char('a'+(i%(26*26))/26);
    }
    cout<<"? "<<s2<<endl;
    cin>>t2;
    
    for(int i=0;i<N;i++){
        s3+=char('a'+i%26);
    }
    cout<<"? "<<s3<<endl;
    cin>>t3;
    
    for(int i=0;i<N;i++){
        int a=t1[i]-'a',b=t2[i]-'a',c=t3[i]-'a';
        ans[a*26*26+b*26+c]=i;
    }
    
    for(int i=0;i<N;i++){
        qu+=rem[ans[i]];
    }
    
    cout<<"! "<<qu<<endl;
    
}