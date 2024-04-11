#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include<stdio.h>


#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<string.h>
using namespace std;
int N=1000;
vector< vector<int> > a(2*N);
vector<int> ans(2*N,0);
void BFS(){
    queue <int>Q;
    Q.push(0);
    ans[0]=0;
    bool was[2*N];
    was[0]=1;
    memset(was,false, 2*N);
    while(!Q.empty()){
        int y=Q.front();
        Q.pop();
        for (int i=0;i<a[y].size();i++){
            int k=a[y][i];
            if(was[k]) continue;
            was[k]=true;
            ans[k]=1+ans[y];
            Q.push(k);
        }
    }
}
int main(){
    int c,d;
    cin>>c;
    cin>>d; 
    for(int i=0;i<c;++i){
        for(int j=0;j<d;++j){
            char k;
            cin>>k;
            if(k=='#'){
               a[i].push_back(j+c);
               a[c+j].push_back(i);
           }
            
        }
    }
    BFS();
    if(ans[c-1]==0) puts("-1");
    else{
        cout<<ans[c-1];
    }
    return 0;
}