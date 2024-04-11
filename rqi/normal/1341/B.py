

t = int(input())

for T in range(t):
    n, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    a = [0] + a + [0]
    csum = (n+1)*[0]
    for i in range(1, n+1, 1):
        if a[i] > a[i-1] and a[i] > a[i+1]:
            csum[i] = 1
    for i in range(1, n+1, 1):
        csum[i]+=csum[i-1]

    t_ans, l_ans = -1, -1
    for l in range(1, n-k+2, 1):
        r = l+k-1
        peak_num = csum[r-1]-csum[l]
        if peak_num > t_ans:
            t_ans = peak_num
            l_ans = l
    print(t_ans+1, l_ans)