#include <cstdio>

int K;
bool adj[92][92];

void edge(int a, int b){ adj[a-1][b-1] = adj[b-1][a-1] = true; }

int main(){
    edge(1, 32);
    edge(2, 33);
    edge(2, 63);

    for(int v=2; v<31; v++){
        edge(v+1, v+2);
        edge(31+v, 32+v);
        edge(31+v, 62+v);
        edge(32+v, 61+v);
        edge(61+v, 62+v);
    }

    scanf("%d", &K);
    if(K&1){ K^=1; edge(2, 3); }

    for(int v=1; v<31; v++)
        if((K>>v)&1){
            edge((1+v)%31 + 2, v+32);
            edge((1+v)%32 + 2, v+62);
        }

    printf("92\n");
    for(int i=0; i<92; i++){
        for(int j=0; j<92; j++)
            printf("%c", adj[i][j]?'Y':'N');
        printf("\n");
    }

    return 0;
}