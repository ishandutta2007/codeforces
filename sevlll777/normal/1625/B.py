for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    if 1:
        kek=N+1
        ae=dict()
        for i in range(N):
            if A[i] in ae:
                kek=min(kek, i-ae[A[i]]) 
            ae[A[i]] = i
        print(N-kek)