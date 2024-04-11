#include<iostream>
#include<vector>
#include<set>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
using namespace std;
int str2int(string a){
    if(a==string("XXL"))
        return 4;
    if(a==string("XL"))
        return 3;
    if(a==string("L"))
        return 2;
    if(a==string("M"))
        return 1;
    return 0;
}
string int2str(int a){
    return a==4?string("XXL"):a==3?string("XL"):a==2?string("L"):a==1?string("M"):string("S");
}
int main(){
    int love[5][5]={{0,1,2,3,4},{1,2,0,3,4},{2,3,1,4,0},{3,4,2,1,0},{4,3,2,1,0}},n[5],k;
    cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4]>>k;
    for(int i=0;i<k;i++){
        string a;
        cin>>a;
        int m=str2int(a);
        int b=0;
        while(!n[love[m][b]])
            b++;
        cout<<int2str(love[m][b])<<'\n';
        n[love[m][b]]--;
    }
    return 0;
}