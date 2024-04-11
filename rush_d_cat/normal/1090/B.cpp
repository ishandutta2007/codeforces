#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N=100000+10;
vector<string> vec;
map<string,int> mp; int tot=0;
string st,ed;
bool ok=0;
struct Item {
    string all,name;
    void read(){
        all=name="";
        char c;
        while(scanf("%c",&c)){
            if(c=='\n')break;
            all+=c;
        }
        if(all[0]=='\\'&&all[1]=='e'&&all[2]=='n') {
            ed=all;
            ok=1;
            return;
        }
        for(int i=9;;i++){
            if(all[i]=='}')break;
            name+=all[i];
        }
    }
    bool operator<(const Item &o)const{
        return mp[name]<mp[o.name];
    }
    void print(){
        cout<<all<<endl;
    }
} it[N];

void read() {
    char c;
    string str=""; st=ed="";
    while(scanf("%c",&c)){
        if(c==' '||c=='\n') {
            if(str[0]=='\\'&&str[1]=='b'&&str[2]=='e') {
                st=str; break;
            }
            if(str[0]=='\\' && str[1]=='c') {
                string paigulong="";
                for(int i=6;;i++){
                    if(str[i]=='}')break;
                    paigulong+=str[i];
                }
                vec.push_back(paigulong); mp[paigulong]=++tot;
            }
            str="";
        } else {
            str+=c;
        }
    }
}
int main() {
    read();
    for(int i=1;;i++) {
        it[i].read();
        if(ok==1) {
            bool ac=1;
            for(int x=2;x<i;x++) {
                if(!(it[x-1]<it[x])) ac=0;
            }
            if(ac) printf("Correct\n");
            else {
                printf("Incorrect\n");
                cout<<st<<endl;
                sort(it+1,it+i);
                for(int x=1;x<i;x++) it[x].print();
                cout<<ed<<endl;
            }
            exit(0);
        }
    }
}