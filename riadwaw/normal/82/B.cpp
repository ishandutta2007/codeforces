#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    set<int> arr[40000];
    int knt=n*(n-1)/2;
    for(int i=0;i<knt;++i){
        int c;
        scanf("%d",&c);
        while(c--){
            int x;
            scanf("%d",&x);
            arr[i].insert(x);
        }
    }
    int first=*arr[0].begin();
    if(n==2){
        cout<<1<<' '<<first<<endl;
        arr[0].erase(first);
        cout<<arr[0].size()<<' ';
        for(set<int>::iterator it=arr[0].begin();it!=arr[0].end();++it){
            cout<<*it<<' ';
        }
        return;
    }
    set<int> good;
    for(int i=1;i<=knt;++i){
        if(arr[i].find(first)!=arr[i].end()){
            for(set<int>::iterator it=arr[0].begin();it!=arr[0].end();++it){
                if(arr[i].find(*it)!=arr[i].end()){
                    good.insert(*it);
                }
            }
            break;
        }
    }
    cout<<good.size()<<' ';
    for(set<int>::iterator it=good.begin();it!=good.end();++it){
        printf("%d ",*it);
    }
    for(int i=0;i<=knt;++i){
        if(arr[i].find(first)!=arr[i].end()){
            vector<int> cur;
            for(set<int>::iterator it=arr[i].begin();it!=arr[i].end();++it){
                if(good.find(*it)==good.end()){
                    cur.pb(*it);
                }
            }
            printf("\n%d ",cur.size());
            for(vector<int>::iterator it=cur.begin();it!=cur.end();++it){
                printf("%d ",*it);
            }
        }
    }
}