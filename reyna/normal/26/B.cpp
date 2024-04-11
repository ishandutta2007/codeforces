#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> V;
int main(){
    string a;
    cin >> a;
    int counter = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '('){
            V.push_back('(');
        }
        if(V.size() != 0){
            if(a[i] == ')'){
                V.pop_back();
                counter+=2;
            }
        }
    }
    cout << counter << endl;
    return 0;
}