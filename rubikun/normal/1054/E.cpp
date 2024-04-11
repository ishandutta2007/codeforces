#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

vector<vector<int>> ans;

void query(int h1,int w1,int h2,int w2){
    ans.push_back({h1+1,w1+1,h2+1,w2+1});
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<string>> A(H,vector<string>(W)),B(H,vector<string>(W));
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
    
    for(int t=si(A[H-1][0])-1;t>=0;t--){
        if(A[H-1][0][t]=='0') query(H-1,0,0,0);
        else query(H-1,0,H-1,W-1);
    }
    
    for(int t=si(A[0][W-1])-1;t>=0;t--){
        if(A[0][W-1][t]=='0') query(0,W-1,0,0);
        else query(0,W-1,H-1,W-1);
    }
    
    for(int t=si(A[0][0])-1;t>=0;t--){
        if(A[0][0][t]=='0'){
            query(0,0,H-1,0);
            query(H-1,0,0,0);
        }else{
            query(0,0,0,W-1);
            query(0,W-1,H-1,W-1);
        }
    }
    
    for(int t=si(A[H-1][W-1])-1;t>=0;t--){
        if(A[H-1][W-1][t]=='0'){
            query(H-1,W-1,H-1,0);
            query(H-1,0,0,0);
        }else{
            query(H-1,W-1,0,W-1);
            query(0,W-1,H-1,W-1);
        }
    }
    
    vector<vector<int>> cnt0(H,vector<int>(W)),cnt1(H,vector<int>(W));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i==0&&j==0) continue;
            if(i==H-1&&j==W-1) continue;
            if(i==0&&j==W-1) continue;
            if(i==H-1&&j==0) continue;
            
            for(int t=si(A[i][j])-1;t>=0;t--){
                if(A[i][j][t]=='0'){
                    if(i){
                        query(i,j,0,j);
                        cnt0[0][j]++;
                    }else{
                        query(i,j,0,0);
                    }
                }else{
                    if(i<H-1){
                        query(i,j,H-1,j);
                        cnt1[H-1][j]++;
                    }else{
                        query(i,j,H-1,W-1);
                    }
                }
            }
        }
    }
    
    for(int j=1;j<W;j++){
        for(int t=0;t<cnt0[0][j];t++) query(0,j,0,0);
    }
    
    for(int j=0;j<W-1;j++){
        for(int t=0;t<cnt1[H-1][j];t++) query(H-1,j,H-1,W-1);
    }
    
    for(int i=1;i<H-1;i++){
        for(int j=0;j<W;j++){
            for(int t=si(B[i][j])-1;t>=0;t--){
                if(B[i][j][t]=='0'){
                    if(j) query(0,0,0,j);
                    query(0,j,i,j);
                }else{
                    if(j<W-1) query(H-1,W-1,H-1,j);
                    query(H-1,j,i,j);
                }
            }
        }
    }
    
    for(int t=si(B[0][0])-1;t>=0;t--){
        if(B[0][0][t]=='0'){
            query(0,0,0,W-1);
            query(0,W-1,0,0);
        }else{
            query(H-1,W-1,0,W-1);
            query(0,W-1,0,0);
        }
    }
    
    for(int t=si(B[H-1][W-1])-1;t>=0;t--){
        if(B[H-1][W-1][t]=='0'){
            query(0,0,0,W-1);
            query(0,W-1,H-1,W-1);
        }else{
            query(H-1,W-1,0,W-1);
            query(0,W-1,H-1,W-1);
        }
    }
    
    for(int j=W-1;j>=1;j--){
        for(int t=si(B[0][j])-1;t>=0;t--){
            if(B[0][j][t]=='0'){
                query(0,0,0,j);
            }else{
                if(j<W-1) query(H-1,W-1,H-1,j);
                query(H-1,j,0,j);
            }
        }
    }
    
    for(int j=W-2;j>=0;j--){
        for(int t=si(B[H-1][j])-1;t>=0;t--){
            if(B[H-1][j][t]=='0'){
                query(0,0,H-1,0);
                if(j) query(H-1,0,H-1,j);
            }else{
                query(H-1,W-1,H-1,j);
            }
        }
    }
    
    cout<<si(ans)<<endl;
    
    for(auto x:ans){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<"\n";
    }
}