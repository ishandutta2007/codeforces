#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define MAX_N 100000
int N;

string str[MAX_N+1];
int arr[MAX_N*5+1];
int ans=0;


int main(){
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++){
        cin>>str[i];
        int cnt=0, t=0;
        bool tf=true;
        for(int j=0; j<str[i].size(); j++){
            if(str[i][j]=='('){
                cnt++;
            }else   cnt--;
        }
        if(cnt>=0){
            for(int j=0; j<str[i].size(); j++){
                if(str[i][j]=='('){
                    t++;
                }else t--;
                if(t<0){
                    tf=false;
                }
            }
            if(tf){
                if(cnt==0){
                    if(arr[0]>0){
                        ans++; arr[0]--;
                    }else arr[0]++;
                }else{
                    if(arr[cnt]<0){
                        arr[cnt]++; ans++;
                    }else{
                        arr[cnt]++;
                    }
                }
            }
        }else{
            for(int j=str[i].size()-1; j>=0; j--){
                if(str[i][j]==')') t++;
                else    t--;
                if(t<0) tf=false;
            }
            if(tf){
                if(arr[-cnt]>0){
                    arr[-cnt]--; ans++;
                }else{
                    arr[-cnt]--;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}