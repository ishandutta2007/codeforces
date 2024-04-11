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
    int n,d,a[1111],c=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(abs(a[i]-a[j])<=d)
                c++;
    cout<<(c*2);
    return 0;
}