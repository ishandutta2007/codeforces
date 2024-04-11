#include <iostream>

using namespace std;

int main() {
    string in, out;
    int N;
    cin >> in >> out;
    cin >> N;
    if(N % 2 == 0){
        cout << "undefined";
    }
    else if(N % 4 == 1){
        if(in == "^"){
            if(out == ">") cout << "cw";
            else cout << "ccw";
        }
        else if(in == ">"){
            if(out == "v") cout << "cw";
            else cout << "ccw";
        }
        else if(in == "v"){
            if(out == "<") cout << "cw";
            else cout << "ccw";
        }
        else if(in == "<"){
              if(out == "^") cout << "cw";
            else cout << "ccw";
        }
    }
     else if(N % 4 == 3){
        if(in == "v"){
            if(out == ">") cout << "cw";
            else cout << "ccw";
        }
        else if(in == "<"){
            if(out == "v") cout << "cw";
            else cout << "ccw";
        }
        else if(in == "^"){
            if(out == "<") cout << "cw";
            else cout << "ccw";
        }
        else if(in == ">"){
              if(out == "^") cout << "cw";
            else cout << "ccw";
        }
    }
}