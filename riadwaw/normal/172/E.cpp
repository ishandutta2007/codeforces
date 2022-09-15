#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
string html;
int pos = 0;
vector<string> query;
struct tag{
    string element;
    vector<tag*> childs;
    tag(const string& b):element(b){}
    
    void parse(){
        
        while(true){
            if(pos==(int)html.size())
                return;
            if(html[pos+1] == '/'){
                pos += 3 + element.size();
                return;
            }
            else{
                int len=0;
                while(html[pos+1+len]!='>')
                    ++len;
                tag* child = new tag(html.substr(pos+1, len));
                childs.pb(child);
                pos += 2 + child->element.size();
                if(child->element.back() == '/'){
                    child->element.erase(child->element.end()-1, child->element.end());
                }
                else
                    child->parse();
            }
        }
    }
    int getAnswer(int index){
        int answer = 0;
        if(query[index] == element){
            ++index;
        }
        if(index == (int)query.size()){
            answer++;
            --index;
        }
        for(tag* child: childs){
            answer += child->getAnswer(index);
        }
        return answer;
    }
    
    
    void go(){
        cout<<"in "<<element<<endl;
        cout<<childs.size()<<" childs found"<<endl;
        for(tag* child: childs){
            child->go();
        }
        cout<<"out"<<element<<endl;
    }
};

void solve(){
    string buf;
    getline(cin, html);
    getline(cin, buf);
    stringstream ss(buf);
    tag root("0");
    root.parse();
    int n;
    ss >> n;
    
    
    
    for(int i=0;i<n;++i){
        query.clear();
        getline(cin, buf);
        //cerr<<buf;
        stringstream sss(buf);
        while(sss >> buf)
            query.push_back(buf);
        cout<<root.getAnswer(0)<<'\n';
    }
}