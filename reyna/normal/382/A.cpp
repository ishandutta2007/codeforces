// In the name of God
#include <iostream>
using namespace std;
int main(){
    string f = "",s = "";
    string in;
    cin >> in;
    string add;
    cin >> add;
    bool k = 0;
    for(int i = 0; i < in.size();i++){
        if(in[i] == '|'){
            k = 1;
            continue;
        }
        if(!k)
            f+=in[i];
        else
            s+=in[i];
    }
    if(f.size()+add.size() < s.size() || s.size()+add.size() < f.size() || (s.size()+f.size()+add.size())%2){
        cout << "Impossible" << endl;
        return 0;
    }
    int ind = 0;
    int tmp = f.size()+s.size();
    while(f.size() != (tmp+add.size())/2){
        f+=add[ind++];
    }
    while(s.size() != (tmp+add.size())/2){
        s+=add[ind++];
    }
    cout << f << "|" << s << endl;
    return 0;
}