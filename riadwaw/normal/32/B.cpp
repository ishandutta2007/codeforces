#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    char a[222];
    cin>>a;
    for(int i=0;a[i];i++){
        if(a[i]=='.'){
            cout<<0;
        }
        else{
            i++;
            if(a[i]=='.')
                cout<<1;
            else
                cout<<2;
        }
    }
    return 0;
}