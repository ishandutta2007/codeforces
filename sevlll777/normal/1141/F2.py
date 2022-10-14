def main():
    n = int(input())
    A = list(map(int, input().split()))
    if n == 1:
        print(1)
        print(1, 1)
        exit(0)
    prefA = [0]
    hah = {}
    for i in A:
        prefA.append(prefA[-1] + i)
    for i in range(n):
        for j in range(i + 1, n + 1):
            s = prefA[j] - prefA[i]
            if s not in hah:
                hah[s] = []
            hah[s].append([i + 1, j])


    def lol(a):
        return a[1], a[0]


    ansq = 0
    bm = []
    for s in hah:
        Q = hah[s]
        cnt = 0
        Q.sort(key=lol)
        ans = []
        for i in Q:
            if i[0] > cnt:
                cnt = i[1]
                ans.append(i)
        if ansq < len(ans):
            ansq = len(ans)
            bm = ans
    print(ansq)
    for i in bm:
        print(i[0], i[1])


main()