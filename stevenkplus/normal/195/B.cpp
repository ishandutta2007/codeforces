//steven i'll start
//turn order: steven, travis

#include <cstdio> //steven java is bad gogogo
int main() { // i don't think we need anything else
    int N, M; //steven we need scanf / printf now lol idk about std:: either
    scanf("%d %d", &N, &M); //travis
    if (M % 2 == 0) { //steven sorry not sure let's just do 2 cases unless you have a better way
        }int a = (M+1)/2; // you forgot to declare a
    int D; //steven how are we doing this i was thinking 2 vars and just inc/dec them
    for (int i = 0; i < N; i++) { //i'm not sure what your vars are, but a determines the next value of a so let's just do that
        printf("%d\n", a); //steven sorry if i just made it hard but i see what you're doing
        //if (a == M-1) {a = (M+1)/2;} // we'll just go case by with if-else-else-...
        //steven should that be == M o.o do you want to comment that out or something
        if (a == M) a = (M + 1) / 2;
 //       else if (M%2 == 1 && a == (M+1)/2) { a--; } // travis now we jsut need cases for the two sides
        else if (2 * a <= M) { //steven
            a = M+1-a; } // travis 
        else { //steven just M - a;
    //        if (M%2 == 0 && a == (M+1)/2) { a++; } // travis
            //else 
            a = M - a; //steven our special cases weren't necesasry i think oh well
        } // yeah i'm being too careful
    }//steven
    } // travis