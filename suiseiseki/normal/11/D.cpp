    #include<cstdio>  
    #include<cstring>  
    #include<iostream>  
    #include<algorithm>  
    using namespace std;  
    #define N 20  
    #define INF 1000000000  
    #define LL long long  
    int a[N][N];  
    LL v[1 << N][N];  
    int m, n;  
    LL sum;  
    int js(int j){  
        int ans = 0;  
        while(1){  
            if(j & 1 == 1)break;  
            ans ++;  
            j >>= 1;  
        }  
        return ans;  
    }  

    int main() {  
        scanf("%d%d", &n, &m);  
        int x, y;  
        sum = 0;  
        memset(v, 0, sizeof(v));  
        memset(a, 0, sizeof(a));  
        for(int i = 0; i < m; i++){  
            scanf("%d%d", &x, &y);  
            a[x - 1][y - 1] = 1;  
            a[y - 1][x - 1] = 1;  
        }  
        for(int i = 0; i < n; i++)v[1 << i][i] = 1;  
        for(int j = 1; j < (1 << n); j++){  
            int fp = js(j); //idfp  
            for(int i = 0; i < n; i++){// i   
                if(j & (1 << i) && v[j][i]){  
                    for(int k = fp; k < n; k++){//fpid  
                        if(a[i][k]){//  
                            if(j & (1 << k)){  
                                if((1 << k | 1 << i) == j)continue;//2  
                                if(k == fp)sum += v[j][i];//  
                            }  
                            else {  
                                v[j | (1 << k)][k] += v[j][i];//  
                            }  
                        }  
                    }  
                }  
            }  
        }  
        sum /= 2;//  
        printf("%I64d\n", sum);  
        return 0;  
    }