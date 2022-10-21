#include <bits/stdc++.h>
using namespace std;

#define MAXN 100050

int n;
int num[MAXN];
set<int> suf;
set<int> sufnew;
set<int> res;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    suf.insert(num[0]);
    res.insert(num[0]);
    for(int i = 1; i < n; i++){
        for(int a : suf){
            sufnew.insert(a|num[i]);
        }
        sufnew.insert(num[i]);
        for(int a : sufnew){
            res.insert(a);
        }
        suf = sufnew;
        sufnew.clear();
    }
    cout << res.size();

}