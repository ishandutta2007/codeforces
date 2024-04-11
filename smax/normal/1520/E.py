from sys import stdin, stdout
input, print = stdin.readline, stdout.write

def main():
    for _ in range(int(input())):
        n = int(input())
        s = input().rstrip()
        k = s.count('*')
        if k == 0:
            print('0\n')
            continue

        cnt = 0
        rightSum = 0
        ckpt = [0] * n
        for i in range(n):
            if s[i] == '*':
                rightSum += i - cnt + 1
                ckpt[i - cnt] += 1
                cnt += 1
        ret = n * n
        left = 0
        right = k
        leftSum = 0
        for i in range(n - k + 1):
            leftSum += left
            rightSum -= right
            left += ckpt[i]
            right -= ckpt[i]
            ret = min(ret, leftSum + rightSum)
        print(str(ret) + '\n')

main()