t = int(input())
for di in range(t):
    n, k = map(int, input().split())
    bua = n // k
    mz = ""
    for i in range(97, 97 + k):
        mz += bua * chr(i)
    mz += chr(97) * (n % k)
    print(mz)