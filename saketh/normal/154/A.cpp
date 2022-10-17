#include <iostream>
#include <map>
using namespace std;

string inp;
int N;
map<char, char> p;

int main(){
    cin >> inp >> N;
    
    for(int i=0; i<N; i++){
        char a, b;
        cin >> a >> b;
        p[a] = b;
        p[b] = a;
    }

    int i = 0, del = 0;

    while(i < inp.size()){
        int a = 0, b = 0;
        
        char fst = inp[i];
        while(i < inp.size() && inp[i] == fst){
            i++;
            a++;
        }
        if(i == inp.size()) break;
        if(p.count(fst) == 0) continue;

        while(i < inp.size() && (inp[i] == fst || inp[i] == p[fst])){
            if(inp[i] == fst) a++;
            else b++;
            i++;
        }

        del += min(a, b);
    }

    cout << del << endl;
    return 0;
}