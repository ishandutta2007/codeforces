#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string answer;
bool bright[505][505];
bool check(int x_1,int y_1,int x_2,int y_2){
    cout<<'?'<<' '<<x_1<<' '<<y_1<<' '<<x_2<<' '<<y_2<<endl;
    cin>>answer;
    if(answer[0]=='Y'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    fflush(stdout);
    int new_x,new_y;
    int left_x=1,left_y=1,right_x=n,right_y=n;
    if(check(left_x,left_y,right_x,right_y)){
        bright[1][1]=1;
        bright[n][n]=1;
    }
    else{
        puts("! -1");
        return 0;
    }
    int nxt_x,nxt_y;
    int ml=2;
    while(ml<=(n<<1)-1){
        new_x=right_x-1;
        new_y=right_y;
        if(new_x>0&&new_x<=n&&new_y>0&&new_y<=n&&new_x>=left_x&&new_y>=left_y&&(new_x-left_x)+(new_y-left_y)>=n-1&&check(left_x,left_y,new_x,new_y)){
            bright[new_x][new_y]=1;
            right_x=new_x;
            right_y=new_y;
            ml++;
        }
        else{
            new_x=right_x;
            new_y=right_y-1;
            if(new_x>0&&new_x<=n&&new_y>0&&new_y<=n&&new_x>=left_x&&new_y>=left_y&&(new_x-left_x)+(new_y-left_y)>=n-1){
                bright[new_x][new_y]=1;
                right_x=new_x;
                right_y=new_y;
                ml++;
            }
            else{
                if(bright[right_x+1][right_y]){
                    nxt_x=right_x+1;
                    nxt_y=right_y;
                }
                else{
                    nxt_x=right_x;
                    nxt_y=right_y+1;
                }
                new_x=left_x;
                new_y=left_y+1;
                if(new_x<=nxt_x&&new_y<=nxt_y&&new_x>0&&new_x<=n&&new_y>0&&new_y<=n&&(nxt_x-new_x)+(nxt_y-new_y)>=n-1&&check(new_x,new_y,nxt_x,nxt_y)){
                    bright[new_x][new_y]=1;
                    left_x=new_x;
                    left_y=new_y;
                    right_x=nxt_x;
                    right_y=nxt_y;
                    ml++;
                }
                else{
                    new_x=left_x+1;
                    new_y=left_y;
                    bright[new_x][new_y]=1;
                    left_x=new_x;
                    left_y=new_y;
                    right_x=nxt_x;
                    right_y=nxt_y;
                    ml++;
                }
            }
        }
    }
    cout<<"! ";
    int x=1,y=1;
    while(x<n||y<n){
        if(y+1<=n&&bright[x][y+1]){
            cout<<'R';
            y++;
        }
        else{
            cout<<'D';
            x++;
        }
    }
    cout<<endl;
    return 0;
}