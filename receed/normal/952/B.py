from sys import stdout

def main():
    ans = 0
    a = ['great', 'think', 'touch', 'bad', 'cool']
    b = ['even', 'serious', 'no way', 'die', 'worse', 'terrible']
    for i in range(10):
        print(i)
        stdout.flush()
        s = input()
        if s == 'no':
            continue
        for t in a:
            if t in s:
                print('normal')
                stdout.flush()
                return
        for t in b:
            if t in s:
                print('grumpy')
                stdout.flush()
                return
        raise BaseException

main()