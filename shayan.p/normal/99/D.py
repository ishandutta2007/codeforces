from math import gcd

def PRINT(a, b) :
        print(str(int(a)) + "/" + str(int(b)))
def solve(n) :
        pre = 0
        while(n > 1 and (n % 2 == 0)) : 
	        pre = pre + 1
	        n = n // 2                
        if(n == 1) :
                PRINT(pre, 1)
                return
        arr = []
        rem = 1
        while(True) :
                rem = rem * 2
                arr.append(int(rem // n))
                rem = rem % n
                if(rem == 1) :
                        break
        k = len(arr)
        ans = 0
        for i in range(0, k) :
                if(arr[i] == 1) : 
                        ans = ans + (2 ** (k-1-i)) * (i+1)
        ans = ans * n + k
        A = ans
        B = 2**k - 1
        G = gcd(A, B)
        A = A // G
        B = B // G
        PRINT(A + B * pre, B)
n = int(input())
solve(n)