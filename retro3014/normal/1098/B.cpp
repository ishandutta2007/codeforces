#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define MAX_N 200000


string str[MAX_N+1];
int N, M;
char c[2][2];
char alpha[4]={'A', 'C', 'G', 'T'};
int t[4]={0, 1, 2, 3};
string ans[MAX_N+1], now[MAX_N+1];
int acnt=-1, ncnt=0, cnt1=0, cnt2;

int main(){
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        cin>>str[i];
        ans[i]=now[i]=str[i];
    }
    for(int k=1; k<=24; k++){
        for(int ii=0; ii<2; ii++){
            for(int jj=0; jj<2; jj++){
                c[ii][jj]=alpha[t[ii*2+jj]];
            }
        }
        ncnt=0;
        for(int i=0; i<N; i++){
            cnt1=0; cnt2=0;
            for(int j=0; j<M; j++){
                if(str[i][j]==c[i%2][j%2]){
                    cnt1++;
                }
                if(str[i][j]==c[i%2][(j+1)%2]){
                    cnt2++;
                }
            }
            if(cnt1>cnt2){
                for(int j=0; j<M; j++){
                    now[i][j]=c[i%2][j%2];
                }
                ncnt+=cnt1;
            }else{
                for(int j=0; j<M; j++){
                    now[i][j]=c[i%2][(j+1)%2];
                }
                ncnt+=cnt2;
            }
        }
        if(ncnt>acnt){ acnt=ncnt;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    ans[i][j]=now[i][j];
                }
            }
        }
        ncnt=0;
        for(int j=0; j<M; j++){
            cnt1=0; cnt2=0;
            for(int i=0; i<N; i++){
                if(str[i][j]==c[i%2][j%2]){
                    cnt1++;
                }
                if(str[i][j]==c[(i+1)%2][j%2]){
                    cnt2++;
                }
            }
            if(cnt1>cnt2){
                for(int i=0; i<N; i++){
                    now[i][j]=c[i%2][j%2];
                }
                ncnt+=cnt1;
            }else{
                for(int i=0; i<N; i++){
                    now[i][j]=c[(i+1)%2][j%2];
                }
                ncnt+=cnt2;
            }
        }
        if(ncnt>acnt){ acnt=ncnt;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    ans[i][j]=now[i][j];
                }
            }
        }
        next_permutation(t, t+4);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}