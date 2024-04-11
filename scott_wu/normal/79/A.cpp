#include <iostream> //scott can't we just BF this?
#include <cstdio> //alex still reading

using namespace std; //scott straight BF works i think

int main() { //alex lol i agree
    int x, y; //scott
    cin >> x >> y; // alex
    
    while (true) { //scott
        if (100 * x + 10 * y < 220) { //alex
            cout << "Hanako\n"; //scott
            break; } //alex
        if (y < 2) { //scott output hanako here
            cout << "Hanako\n"; //alex oh i see oops
            break; } //scott
        if (x >= 2) { //alex, got all the cases right?
            x -= 2; y -= 2; //scott yeah i think so
        } else if (x == 1) { // alex
            x -= 1; y -= 12; //scott
        } else { // alex x == 0
            y -= 22; } //scott now we do same thing for ciel as we did in line 11-16
        
        if (100 * x + 10 * y < 220 || y < 2) { //alex
            cout << "Ciel\n"; break; }//scott
        if (y >= 22) { y -= 22; } //alex
        else if (y >= 12) { x--; y -= 12; } //scott
        else { x -= 2; y -= 2; } // alex
    } //scott
    return 0; //alex
} //scott GG