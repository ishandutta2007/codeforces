while True:
    try:
        input()
        print("NO", flush=True)
    except EOFError:
        break