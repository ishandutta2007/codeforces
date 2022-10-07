#include<bits/stdc++.h>
using namespace std;
int a[109][109];
int dx[8][3] ={
{0,0,0},
{0,0,1},
{0,1,1},
{1,1,1},
{0,1,2},
{1,1,2},
{1,2,2},
{1,2,3}
};
int dy[8][3] ={
{1,2,3},
{1,2,2},
{1,1,2},
{0,1,2},
{1,1,1},
{0,1,1},
{0,0,1},
{0,0,0}
};

    int n;
    int ask(int x, int y, int a, int b){
        cout<<"? "<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
        int k;
        cin>>k;
        return k;
    }
void flip(){
    for(int i =1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        if((i+j)%2==1) a[i][j]^=1;
    }
}
void prnt(){
    cout<<"!\n";
    for(int i =1; i <= n; i++){
    for(int j = 1; j <= n; j++)
            cout<<a[i][j];
    cout<<"\n";}
    fflush(stdout);
}
main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            if((i+j)%2) continue;
            if(i+j == 2) {a[i][j] = 1; continue;}
            if(i+j == 2*n) continue;
            if(i >= 3) a[i][j] = a[i][j] = a[i-2][j] ^ (1- ask(i-2,j,i,j)); else
            if(j >= 3) a[i][j] = a[i][j] = a[i][j-2] ^ (1- ask(i,j-2,i,j)); else
            a[i][j] = a[i][j] = a[i-1][j-1] ^ (1- ask(i-1,j-1,i,j));
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i+j)%2==0) continue;
            if(i+j==3) {a[i][j] = 1; continue;}
            if(i >= 4) a[i][j] = a[i][j] = a[i-2][j] ^ (1- ask(i-2,j,i,j)); else
            if(j >= 3) a[i][j] = a[i][j] = a[i][j-2] ^ (1- ask(i,j-2,i,j)); else
            a[i][j] = a[i][j] = a[i-1][j-1] ^ (1- ask(i-1,j-1,i,j));
        }
    }
    for(int j =2; j <=n; j+=2)
        a[1][j] = a[2][j+1] ^ (1 - ask(1,j,2,j+1));
    for(int i =1 ; i <= n; i++)
    for(int j = 1; j <= n; j++){
        int fl0 = 0, fl1 = 0, K = 0;
        for(int k = 0; k < 8; k++){
            if(i+dx[k][2] > n || j + dy[k][2] > n) continue;
            int u = a[i][j] ^ a[i+dx[k][2]][j+dy[k][2]];
            int v = a[i+dx[k][1]][j+dy[k][1]] ^ a[i+dx[k][0]][j+dy[k][0]];
            if(u == 0 && v == 0) fl0 = 1, K = k;
            if(u == 1 && v == 1) fl1 = 1, K = k;
        }
        if(fl0 == fl1) continue;
        if(ask(i,j,i+dx[K][2], j+dy[K][2])){
            if(fl1) flip();
        }
        else if(fl0) flip();
        prnt();
        return 0;
    }

}