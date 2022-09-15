#include <iostream>
#include <map>
using namespace std;
int main(){
    char c[5];
    map<char,map<char,bool> > a;
    for(int i=0;i<3;i++){
        cin>>c;
        a[c[0]][c[2]]=c[1]=='>';
        a[c[2]][c[0]]=c[1]=='<';
    }
    if(a['A']['B'] && a['B']['C'] && a['A']['C'])
        cout<<"CBA";
    else if(a['A']['B'] && a['C']['B'] && a['A']['C'])
        cout<<"BCA";
    else if(a['B']['A'] && a['A']['C'] && a['B']['C'])
        cout<<"CAB";
    else if(a['B']['A'] && a['C']['A'] && a['B']['C'])
        cout<<"ACB";
    else if(a['A']['B'] && a['C']['A'] && a['C']['B'])
        cout<<"BAC";
    else if(a['B']['A'] && a['C']['A'] && a['C']['B'])
        cout<<"ABC";
    else
        cout<<"Impossible";
    return 0;
}