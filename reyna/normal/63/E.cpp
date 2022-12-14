// In the name of God
#include <iostream>
#include <vector>
using namespace std;
int L[19],R[19],D[19];
int dp[1<<19];
vector<int> moves;
int inp[19];
int dfs(int v,int now,int dep,int *arr){
    if(now-1 == dep){
        return 0;
    }
    int ret = 0;
    if(arr[v] != -1)
        ret+=dfs(arr[v],now+1,dep,arr);
    return ret+(1<<(v));
}
bool win(int now){
//  cerr << now << endl;
    if(dp[now] != -1)
        return dp[now];
    for(int i = 0; i < moves.size();i++){
    //cerr << now << endl;
        int move = moves[i];
        if((now & move) == move && !win((now ^ move))){
//          cerr << move << " " << now << endl;
            return dp[now] = 1;
        }
    }
    return dp[now] = 0;
}
int main(){
    R[0] = 1,L[0] = 3,D[0] = 4;
    R[1] = 2,L[1] = 4,D[1] = 5;
    R[2] = -1,L[2] = 5,D[2] = 6;
    R[3] = 4,L[3] = 7,D[3] = 8;
    R[4] = 5,L[4] = 8,D[4] = 9;
    R[5] = 6,L[5] = 9,D[5] = 10;
    R[6] = -1,L[6] = 10,D[6] = 11;
    R[7] = 8,L[7] = -1,D[7] = 12;
    R[8] = 9,L[8] = 12,D[8] = 13;
    R[9] = 10,L[9] = 13,D[9] = 14;
    R[10] = 11,L[10] = 14,D[10] = 15;
    R[11] = -1,L[11] = 15,D[11] = -1;
    R[12] = 13,L[12] = -1,D[12] = 16;
    R[13] = 14,L[13] = 16,D[13] = 17;
    R[14] = 15,L[14] = 17,D[14] = 18;
    R[15] = -1,L[15] = 18,D[15] = -1;
    R[16] = 17,L[16] = -1,D[16] = -1;
    R[17] = 18,L[17] = -1,D[17] = -1;
    R[18] = -1,L[18] = -1,D[18] = -1;
    for(int i = 0; i < 19;i++){
        for(int j = 0; j < 5; j++){
            moves.push_back(dfs(i,0,j,R));
            moves.push_back(dfs(i,0,j,L));
            moves.push_back(dfs(i,0,j,D));
//          if(!i)
//          cerr << dfs(i,0,j,R) << " " << dfs(i,0,j,L) << " " << dfs(i,0,j,D) << " " << i << " " << j << endl;
        }
    }
    dp[0] = 0;
    for(int i = 1; i < 1<<19;i++)
        dp[i] = -1;
    int call = 0;
    for(int i = 0; i < 19;i++){
        char bit;
        cin >> bit;
        if(bit == 'O'){
            inp[i]=1;
        //  cerr <<i << endl;
        }
        
    }
    for(int i = 18;i >= 0;i--){
        call = call * 2 + inp[i];
    //  cerr << call << endl;
    } 
//  cerr << call << endl;
    if(win(call))
        cout << "Karlsson" << endl;
    else
        cout << "Lillebror" << endl;
    return 0;
}