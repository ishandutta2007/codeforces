ans = [3]
k = 2
while ans[-1] + k * 2 < 10 ** 9:
    k*=2
    ans.append(ans[-1]+k)
for t in range(int(input())):
    n = int(input())
    for i in ans:
        if n % i == 0:
            print(n//i)
            break