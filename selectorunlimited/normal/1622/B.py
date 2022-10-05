import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    P=list(map(int,input().split()))
    S=input().strip()

    A=[-1]*n
    MINUS=[]
    PLUS=[]

    for i in range(n):
        if S[i]=="0":
            MINUS.append((P[i],i))
        else:
            PLUS.append((P[i],i))

    #print(MINUS)
    #print(PLUS)

    MAX=n
    MIN=1

    MINUS=sorted(MINUS)
    PLUS=sorted(PLUS)

    #print(MINUS)
    #print(PLUS)

    for x,i in PLUS[::-1]:
        A[i]=MAX
        MAX-=1

    for x,i in MINUS:
        A[i]=MIN
        MIN+=1

    #print(A)

    ANS=[-1]*n

    for i in range(n):
        ANS[i]=A[i]

    #print(ANS)

    print(*ANS)