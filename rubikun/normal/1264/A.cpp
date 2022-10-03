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
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int a=0,b=0,c=0;
        while(a<N&&A[a]==A[0]) a++;
        a--;
        b=a+(a+1)+1;
        while(b<N&&A[b]==A[a+(a+1)+1]) b++;
        b--;
        c=N/2-1;
        while(c>=0&&A[c]==A[N/2]) c--;
        
        if(N/2>=c+1&&a+1<b-a&&a+1<c-b&&a+1>0){
            cout<<a+1<<" "<<b-a<<" "<<c-b<<"\n";
        }
        else cout<<"0 0 0"<<"\n";
        
        T--;
    }
    
}