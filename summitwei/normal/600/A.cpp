#include <bits/stdc++.h>
using namespace std;

bool hasOnlyNumbers(string testPls){
    if(testPls.length() == 0){
        return false;
    }
    for(int blah=0; blah<testPls.length(); blah++){
        if(testPls[blah] < 48 || testPls[blah] > 57){
            return false;
        } else if(blah == 0 && testPls[blah] == '0' && (testPls.length() > 1)){
            return false;
        }
    }
    return true;
}
int main(){
    string why;
    cin >> why;

    string nums = "";
    string notNums = "";
    
    string tempString = "";
    for(int i=0; i<why.length(); i++){
        if(why[i]==';' || why[i]==','){
            if(hasOnlyNumbers(tempString)){
                nums+=tempString;
                nums+=",";
                tempString="";
            } else{
                notNums+=tempString;
                notNums+=",";
                tempString="";
            }
        } else{
            tempString+=why[i];
        }
    }

    if(hasOnlyNumbers(tempString)){
        nums+=tempString;
        nums+=",";
        tempString="";
    } else{
        notNums+=tempString;
        notNums+=",";
        tempString="";
    }

    if(nums.length() == 0){
        nums = "-";
    } else{
        nums.erase(nums.end()-1);    
        nums = "\"" + nums + "\"";
    }

    if(notNums.length() == 0){
        notNums = "-";
    } else{
        notNums.erase(notNums.end()-1);    
        notNums = "\"" + notNums + "\"";
    }

    cout << nums << "\n" << notNums;
    return 0;
}