#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int n, d, usr;
map<string, int> nam;
string src, dst;
int tim, lat;
int las[2010][2010], isf[2010][2010], que[1010][3], pus, pop, ans[1010][2], anl;
string rev[2010];
int getId(string x){
    if(nam.find(x) == nam.end()){
        rev[usr] = x;
        nam[x] = usr++;
        return usr-1;   
    }   
    return nam[x];
}
int main(){
    cin >> n >> d;
    usr = 0;
    nam.clear();
    for(int i=0;i<n;i++){
        cin >> src >> dst >> tim;
        tim++;
        
        if(i!=0&&tim!=lat){
            for(;pop<pus;pop++){
                las[que[pop][0]][que[pop][1]] = que[pop][2]   ;
            }   
        }
        lat = tim;
        
        int fro = getId(src), to = getId(dst);
        if(las[to][fro] >= tim - d && las[to][fro] > 0){
            if(!isf[fro][to]){
                ans[anl][0] = fro;
                ans[anl][1] = to;
                anl++;
                isf[fro][to] = 1;
                isf[to][fro] = 1;
            }   
        }
        que[pus][0] = fro;
        que[pus][1] = to;
        que[pus++][2] = tim;
    }
    cout << anl << endl;
    for(int i=0;i<anl; i++)cout << rev[ ans[i][0] ] << " " << rev[ ans[i][1] ] << endl;
    //scanf(" ");
    return 0;
}