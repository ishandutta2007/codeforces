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
#endif
    solve();
    return 0;
}
void solve(){
    int n,m,k,t;
    pi bad[1010];
    cin>>n>>m>>k>>t;
    for(int i=0;i<k;++i){
        scanf("%d%d",&bad[i].first,&bad[i].second);
    }
    for(int i=0;i<t;++i){
        pi a;
        scanf("%d%d",&a.first,&a.second);
        int c=0;
        bool f=false;
        for(int j=0;j<k;++j){
            if(a==bad[j]){
                printf("Waste\n");
                f=true;
                break;
            }
            else if(a>bad[j])
                ++c;
        }
        if(f)
            continue;
        int num=((a.first-1)*m)+a.second-c;
        switch(num%3){
            case 1:
                printf("Carrots");
                break;
            case 2:
                printf("Kiwis");
                break;
            case 0:
                printf("Grapes");
        }
        printf("\n");
    }
}