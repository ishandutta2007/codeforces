#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    char c;
    vector<int> a;
    int res[5000],cres=0;
    while(cin>>c){
        cin>>c;
        if(c=='/'){
            cin>>c>>c;
            if(c=='a'){
                res[cres++]=(a[a.size()-1]);
                a.pop_back();
                cin>>c>>c>>c>>c;
            }
            else{
                cin>>c;
            }
        }
        else{
            cin>>c;
            if(c=='a'){
                a.push_back(0);
                cin>>c>>c>>c>>c;
            }
            else if(c=='d'){
                a[a.size()-1]++;
                cin>>c;
            }
            else{
                cin>>c;
            }
        }
    }
    sort(res,res+cres);
    for(int i=0;i<cres;++i)
        cout<<res[i]<<' ';
    return 0;
}