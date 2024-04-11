#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<int>> A(H,vector<int>(W)),B(H,vector<int>(W));
    bool ok=true;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>B[i][j];
        }
    }
    
    for(int s=0;s<H+W-1;s++){
        vector<int> a,b;
        for(int j=0;j<W;j++){
            if(0<=s-j&&s-j<H){
                a.push_back(A[s-j][j]);
                b.push_back(B[s-j][j]);
            }
        }
        sort(all(a));
        sort(all(b));
        
        if(a!=b) ok=false;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}