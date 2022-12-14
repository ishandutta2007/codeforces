#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

#define MAX_N 100
using namespace std;

int N;
vector<int> v;
int x;
int y=0;

int main(){
    scanf("%d", &N);
    v.push_back(0);
    for(int i=1; i<=N; i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    v.push_back(1001);
    x=0;
    for(int i=1; i<v.size()-1; i++){
        if(v[i-1]==v[i]-1 && v[i]==v[i+1]-1){
            x++;
        }else{
            y=max(y, x);
            x=0;
        }
    }
    y=max(y, x);
    cout<<y;
    return 0;
}