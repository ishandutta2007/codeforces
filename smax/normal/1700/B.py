from sys import stdin, stdout
input, print = stdin.readline, stdout.write

for _ in range(int(input())):
    n = int(input())
    s = input()
    if (s[0] == '9'):
        print(str(int('1' * (n + 1)) - int(s)) + '\n')
    else:
        print(str(int('9' * n) - int(s)) + '\n')