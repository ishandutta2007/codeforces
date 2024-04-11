#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

deque<char> dq;
string str;
int one;

int main(){
    cin>>str;
    for(int i=0; i<str.size(); i++){
        if(str.at(i)=='0' || str.at(i)=='2'){
            dq.push_back(str.at(i));
        }
        else one++;
    }
    while(!dq.empty() && dq.front()=='0'){
        printf("%c", dq.front());
        dq.pop_front();
    }
    while(one--){
        printf("1");
    }
    while(!dq.empty()){
        printf("%c", dq.front());
        dq.pop_front();
    }
    return 0;
}